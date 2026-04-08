use std::env;
use std::fs;
use std::os::unix::fs::{MetadataExt, PermissionsExt};
use std::io::Write;
use std::process::{Command, Stdio};
use std::path::Path;

const NR_OF_SUPPORTED_LANG: usize = 11;
const CARD_LEN: usize = 15;
const MAX_SIZE_ELEMENT: usize = 15;
const SUPPORTED_GROUPS: usize = 11;
const ERRR: u32 = 0xFFFAFFF;

#[derive(Clone, Copy)]
struct TypeInfo {
    name: &'static str,
    counted_size: u64,
    globalsumindex: usize,
}

static mut TYPES: [TypeInfo; NR_OF_SUPPORTED_LANG] = [
    TypeInfo { name: "",    counted_size: 0, globalsumindex: 0 },
    TypeInfo { name: "c",   counted_size: 0, globalsumindex: 1 },
    TypeInfo { name: "cpp", counted_size: 0, globalsumindex: 2 },
    TypeInfo { name: "ino", counted_size: 0, globalsumindex: 3 },
    TypeInfo { name: "py",  counted_size: 0, globalsumindex: 4 },
    TypeInfo { name: "java",counted_size: 0, globalsumindex: 5 },
    TypeInfo { name: "sh",  counted_size: 0, globalsumindex: 6 },
    TypeInfo { name: "js",  counted_size: 0, globalsumindex: 7 },
    TypeInfo { name: "html",counted_size: 0, globalsumindex: 8 },
    TypeInfo { name: "asm", counted_size: 0, globalsumindex: 9 },
    TypeInfo { name: "rs",  counted_size: 0, globalsumindex: 10 },
];

static NAME_LIST: [&str; NR_OF_SUPPORTED_LANG] = [
    "undefind", "C", "C++", "ESP", "Python", "Java", "ShellScript",
    "JavaScript", "HTML", "Assembly", "Rust",
];

static COLOR_LIST: [u64; NR_OF_SUPPORTED_LANG] = [
    0x2222077877CC, 0x222205666666, 0x22220A2222FF, 0x22220FEEAA00,
    0x222200A8A862, 0x222200FFFF00, 0x222200FF0010, 0x222200BB0010,
    0x222200888888, 0x222200FF8800, 0x222200DEA584,
];

fn mode_to_str(mode: u32) -> String {
    let mut s = String::with_capacity(11);
    s.push(match mode & 0o170000 {
        0o040000 => 'd', 0o120000 => 'l', 0o020000 => 'c',
        0o060000 => 'b', 0o010000 => 'p', 0o140000 => 's',
        _ => '-',
    });
    s.push(if mode & 0o400 != 0 { 'r' } else { '-' });
    s.push(if mode & 0o200 != 0 { 'w' } else { '-' });
    s.push(if mode & 0o100 != 0 { 'x' } else { '-' });
    s.push(if mode & 0o040 != 0 { 'r' } else { '-' });
    s.push(if mode & 0o020 != 0 { 'w' } else { '-' });
    s.push(if mode & 0o010 != 0 { 'x' } else { '-' });
    s.push(if mode & 0o004 != 0 { 'r' } else { '-' });
    s.push(if mode & 0o002 != 0 { 'w' } else { '-' });
    s.push(if mode & 0o001 != 0 { 'x' } else { '-' });
    s
}

fn process_size(size: u64) -> String {
    let units = ["B", "KB", "MB", "GB", "TB"];
    let mut s = size as f64;
    let mut u = 0usize;
    while s >= 1024.0 && u < 4 {
        s /= 1024.0;
        u += 1;
    }
    format!("{:.1} {}", s, units[u])
}

fn utf8_char_len(c: u8) -> usize {
    if c < 0x80 { 1 }
    else if (c >> 5) == 0b110 { 2 }
    else if (c >> 4) == 0b1110 { 3 }
    else if (c >> 3) == 0b11110 { 4 }
    else { 1 }
}

fn colorama_print(text: &str, col: u64) -> String {
    let bg_r = ((col >> 40) & 0xFF) as u8;
    let bg_g = ((col >> 32) & 0xFF) as u8;
    let bg_b = ((col >> 24) & 0xFF) as u8;
    let fg_r = ((col >> 16) & 0xFF) as u8;
    let fg_g = ((col >> 8)  & 0xFF) as u8;
    let fg_b = (col & 0xFF) as u8;
    format!("\x1b[38;2;{};{};{}m\x1b[48;2;{};{};{}m{}\x1b[0m",
            fg_r, fg_g, fg_b, bg_r, bg_g, bg_b, text)
}

fn colorama_fillup(text: &str, color: u64) -> String {
    let mut res = String::with_capacity(CARD_LEN);
    let mut pos = 0;
    let mut i = 0;
    let bytes = text.as_bytes();
    while pos < CARD_LEN && i < bytes.len() {
        let clen = utf8_char_len(bytes[i]);
        if pos + clen > CARD_LEN { break; }
        res.push_str(&text[i..i + clen]);
        pos += clen;
        i += clen;
    }
    while pos < CARD_LEN {
        res.push(' ');
        pos += 1;
    }
    colorama_print(&res, color)
}

fn coll(text: &str, col: u64) -> String {
    let r = ((col >> 16) & 0xFF) as u8;
    let g = ((col >> 8)  & 0xFF) as u8;
    let b = (col & 0xFF) as u8;
    format!("\x1b[38;2;{};{};{}m{}\x1b[0m", r, g, b, text)
}

fn chngg(text: &str, color: u64, more_space: bool) -> String {
    let max_len = if more_space { MAX_SIZE_ELEMENT * 3 } else { MAX_SIZE_ELEMENT };
    let mut res = String::with_capacity(max_len);
    let mut pos = 0;
    let mut i = 0;
    let bytes = text.as_bytes();
    while pos < max_len && i < bytes.len() {
        let clen = utf8_char_len(bytes[i]);
        if pos + clen > max_len { break; }
        res.push_str(&text[i..i + clen]);
        pos += clen;
        i += clen;
    }
    while pos < max_len {
        res.push(' ');
        pos += 1;
    }
    coll(&res, color)
}

fn get_type_ind_by_name(type_s: &str) -> u32 {
    unsafe {
        let arr = &raw const TYPES;
        for (i, t) in (*arr).iter().enumerate().skip(1) {
            if t.name == type_s {
                return i as u32;
            }
        }
    }
    ERRR
}

fn add_type_value(pp_index: usize, filesize: u64) {
    if pp_index >= NR_OF_SUPPORTED_LANG { return; }
    unsafe {
        let arr = &raw mut TYPES;
        (*arr)[pp_index].counted_size += filesize;
    }
}

fn get_type(fullpath: &str, filesize: u64) {
    if let Some(dot_pos) = fullpath.rfind('.') {
        let ext = &fullpath[dot_pos + 1..];
        if !ext.contains('/') {
            let idx = get_type_ind_by_name(ext);
            if idx != ERRR {
                add_type_value(idx as usize, filesize);
            }
        }
    }
}

fn folder_size(path: &Path) -> u64 {
    let mut total = 0u64;
    if let Ok(entries) = fs::read_dir(path) {
        for e in entries.filter_map(Result::ok) {
            let p = e.path();
            if let Ok(meta) = fs::symlink_metadata(&p) {
                if meta.is_dir() {
                    total += folder_size(&p);
                } else {
                    let sz = meta.len();
                    total += sz;
                    if let Some(s) = p.to_str() {
                        get_type(s, sz);
                    }
                }
            }
        }
    }
    total
}

fn get_dom_lang_index() -> usize {
    let mut local_sums = [0u64; SUPPORTED_GROUPS];
    unsafe {
        let arr = &raw const TYPES;
        for i in 1..NR_OF_SUPPORTED_LANG {
            let t = &(*arr)[i];
            let g = t.globalsumindex;
            if g < SUPPORTED_GROUPS {
                local_sums[g] += t.counted_size;
            }
        }
    }
    let mut max_idx = 0;
    let mut max_size = 0u64;
    for (i, &s) in local_sums.iter().enumerate() {
        if s > max_size {
            max_size = s;
            max_idx = i;
        }
    }
    unsafe {
        let arr = &raw mut TYPES;
        for t in &mut (*arr) {
            t.counted_size = 0;
        }
    }
    max_idx
}

fn get_dom_single_file_index(path: &Path) -> usize {
    let path_str = path.to_string_lossy();
    let extra = if let Some(pos) = path_str.rfind('.') {
        &path_str[pos + 1..]
    } else {
        ""
    };
    unsafe {
        let types = &raw const TYPES;
        for (i, t) in (*types).iter().enumerate() {
            if t.name == extra {
                return i;
            }
        }
    }
    0
}

fn main_lll() -> Result<(), Box<dyn std::error::Error>> {
    let mut entries: Vec<(u64, String)> = vec![];
    for entry in fs::read_dir(".")? {
        let entry = entry?;
        let path = entry.path();
        let name = entry.file_name().to_string_lossy().into_owned();
        if name == "." || name == ".." { continue; }
        let meta = fs::symlink_metadata(&path)?;
        let mode = meta.permissions().mode();
        let perms = mode_to_str(mode);
        let links = meta.nlink();
        let owner = users::get_user_by_uid(meta.uid())
            .map(|u| u.name().to_string_lossy().into_owned())
            .unwrap_or_else(|| format!("uid:{}", meta.uid()));
        let group = users::get_group_by_gid(meta.gid())
            .map(|g| g.name().to_string_lossy().into_owned())
            .unwrap_or_else(|| format!("gid:{}", meta.gid()));
        let size_str = if meta.is_dir() {
            process_size(folder_size(&path))
        } else {
            process_size(meta.len())
        };
        let mtime = meta.modified().unwrap_or(std::time::SystemTime::UNIX_EPOCH);
        let timestr = chrono::DateTime::<chrono::Local>::from(mtime)
            .format("%e. %b %H:%M")
            .to_string();
        let lang_idx;
        if meta.is_dir() {
            lang_idx = get_dom_lang_index();
        } else {
            lang_idx = get_dom_single_file_index(&path);
        }
        let is_dir = meta.is_dir();
        let name_color = if is_dir { 0x9999FF } else { 0xFF33FF };
        let line = if meta.is_symlink() {
            if let Ok(target) = fs::read_link(&path) {
                format!("{} {:2} {} {} {:8} {} {} -> {}",
                    perms, links, owner, group, size_str, timestr, name, target.display())
            } else {
                format!("{} {:2} {} {} {:8} {} {}", perms, links, owner, group, size_str, timestr, name)
            }
        } else {
            format!("{} {:2} {} {} {:8} {} {} {}",
                perms,
                links,
                chngg(&owner,     0x44FF44, false),
                chngg(&group,     0x88FF88, false),
                chngg(&size_str,  0xFF0000, false),
                chngg(&timestr,   0x888866, false),
                colorama_fillup(NAME_LIST[lang_idx], COLOR_LIST[lang_idx]),
                chngg(&name, name_color, true)
            )
        };
        let ts = mtime.duration_since(std::time::UNIX_EPOCH).unwrap_or_default().as_secs();
        entries.push((ts, line));
    }
    entries.sort_by(|a, b| b.0.cmp(&a.0));
    entries.reverse();
    for (_, line) in entries {
        println!("{}", line);
    }
    Ok(())
}

fn get_absolute_path(name: &str) {
    match env::current_dir() {
        Ok(mut path) => {
            path.push(name);
            if let Some(path_str) = path.to_str() {
                println!("{}", path_str);
                clipper(path_str);
            }
        }
        Err(e) => eprintln!("ERROR: getcwd: {}", e),
    }
}

fn clipper(content: &str) {
    let mut child = Command::new("xclip")
        .arg("-selection")
        .arg("clipboard")
        .stdin(Stdio::piped())
        .spawn()
        .expect("Fehler: xclip konnte nicht gestartet werden");
    if let Some(mut stdin) = child.stdin.take() {
        stdin.write_all(content.as_bytes()).unwrap();
    }
    let _ = child.wait(); // Warten, bis xclip fertig ist
}

fn main() {
    if env::args().len() == 1 {
        if let Err(e) = main_lll() {
            eprintln!("Error: {}", e);
        }
    }
    if env::args().len() == 2 {
        if let Some(name) = env::args().nth(1) {
            get_absolute_path(&name);
        } else {
            eprintln!("Bitte einen Namen als Parameter übergeben.");
        }
    }
}

