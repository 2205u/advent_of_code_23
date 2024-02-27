struct RGB(i32, i32, i32);

impl RGB {
    fn is_possible(&self) -> bool {
        self.0 <= 12 && self.1 <= 13 && self.2 <= 14
    }

    fn reset(&mut self) {
        self.0 = 0;
        self.1 = 0;
        self.2 = 0;
    }
}

enum Color {
    Red,
    Green,
    Blue
}

impl Color {
    fn from(str: &str) -> Self {
        match str {
            "red" => Color::Red,
            "blue" => Color::Blue,
            "green" => Color::Green,
            &_ => panic!(),
        }
    }
}


fn main() {
    let puzzle_input = include_str!("./puzzle_input.txt");
    let mut answer = 0;
    
    // One line = One game
    for line in puzzle_input.lines() {
        // Words in that one line
        let mut words: Vec<_>= line.split_whitespace().collect();
        words.remove(0); // Remove "Game"
 
        let game_id = words[0].replace(":", "").parse::<i32>().unwrap();
        words.remove(0); // Remove <Game ID>

        // Game is possible by default
        let mut is_possible = true;

        // round = X red, Y green, Z blue; Multiple rounds in one game.
        for round in words.split_inclusive(|s| s.ends_with(";")) {

            let mut ball_count: RGB = RGB(0, 0, 0);
            let mut temp_color_store :i32 = 0;

            // word = [X, red, Y, green, Z, blue, ...]
            for word in round {

                match word {

                    end_colour if end_colour.ends_with(";") => {
                        let colour = Color::from(&end_colour.replace(";", ""));
                        match colour {
                            Color::Red => {
                                ball_count.0 += temp_color_store;
                            },
                            Color::Green => {
                                ball_count.1 += temp_color_store;
                            },
                            Color::Blue => {
                                ball_count.2 += temp_color_store;
                            },
                        };

                        if !ball_count.is_possible() {
                            is_possible = false;
                        }

                        ball_count.reset();
                    },

                    num if num.parse::<i32>().is_ok() => {
                        temp_color_store = num.parse::<i32>().unwrap();
                    },

                    color => {
                        match color {
                            &"red," => {
                                ball_count.0 += temp_color_store;
                            },
                            &"green," => {
                                ball_count.1 += temp_color_store;
                            },
                            &"blue," => {
                                ball_count.2 += temp_color_store;
                            },
                            &"red" => {
                                ball_count.0 += temp_color_store;
                                if !ball_count.is_possible() {
                                    is_possible = false;
                                }
                           },
                            &"green" => {
                                ball_count.1 += temp_color_store;
                                if !ball_count.is_possible() {
                                    is_possible = false;
                                }
                            },
                            &"blue" => {
                                ball_count.2 += temp_color_store;
                                if !ball_count.is_possible() {
                                    is_possible = false;
                                }
                            },
                            &&_ => panic!()
                        }
                    },
                }
            }
        }
        if is_possible {
            answer += game_id;
        }
    }
    println!("{}", answer);
}
