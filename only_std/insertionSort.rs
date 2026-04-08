fn insertion_sort(arr: &mut [i32]) {
    for i in 1..arr.len() {
        let key = arr[i];
        let mut j = i as isize - 1;
        while j >= 0 && arr[j as usize] > key {
            arr[j as usize + 1] = arr[j as usize];
            j -= 1;
        }
        arr[j as usize + 1] = key;
    }
}

fn print_array(arr: &[i32]) {
    for &num in arr {
        print!("{} ", num);
    }
    println!();
}

fn main() {
    let mut arr = [12, 11, 13, 5, 6];
    println!("Unsortiertes Array:");
    print_array(&arr);
    insertion_sort(&mut arr);
    println!("Sortiertes Array:");
    print_array(&arr);
}

