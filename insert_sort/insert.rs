fn main() {
    let mut arr = [2, 5, 3, 5, 6, 8, 1];
    insert_sort(&mut arr);
    println!("{:?}", arr);
}

fn insert_sort(arr: &mut [i32]) {
    for i in 1..arr.len() {
        let mut j = i;
        while j > 0 && arr[j - 1] > arr[j] {
            arr.swap(j, j - 1);
            j -= 1;
        }
    }
}
