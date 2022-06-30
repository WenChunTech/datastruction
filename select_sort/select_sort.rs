fn main() {
    let mut arr = [1, 3, 2, 5, 8, 3, 9, 4];
    select_sort(&mut arr);
    println!("{:?}", arr);
}

fn select_sort(arr: &mut [i32]) {
    for i in 0..arr.len() {
        let mut min_index = i;
        for j in i..arr.len() {
            if arr[j] < arr[min_index] {
                min_index = j;
            }
        }
        arr.swap(i, min_index);
    }
}
