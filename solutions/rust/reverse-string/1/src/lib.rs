use unicode_segmentation::UnicodeSegmentation;

pub fn reverse(input: &str) -> String {
    let mut output = String::from("");

    for ch in String::from(input).graphemes(true).rev() {
        output.push_str(ch);
    }

    output
}
