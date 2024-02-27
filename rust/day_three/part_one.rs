fn main() {
    let puzzle_input = include_str!("puzzle_input.txt"); 
    
    let mut arr: Vec<_> = Vec::new();
    for line in puzzle_input.lines() {
        for word in line.chars() {
            arr.push(word);
        }
    }
}

// init sum = 0
// convert puzzle input into arr where one char is one element
// iterate over arr
// if current element == symbol
// sum += find_adjacent_numbers(symbol).elements()
