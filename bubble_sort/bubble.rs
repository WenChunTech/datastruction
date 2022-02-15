fn bubble_sort<T>(arr: &mut Vec<T>)
where
    T: PartialOrd,
{
    let mut i = 0;
    while i < arr.len() - 1 {
        let mut j = 0;
        while j < arr.len() - i - 1 {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
            j += 1;
        }
        i += 1;
    }
}
fn main() {
    let mut v = vec![
        100, 20, 999, 432, 0, 99, 23, 15, 77777, 432, 123, 2, 123, 900,
    ];
    bubble_sort(&mut v);
    println!("{:?}", v);
}
