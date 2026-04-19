use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let base: Vec<_> = word.to_lowercase().chars().collect();
    let mut sorted_base = base.clone();
    sorted_base.sort_unstable();

    let mut result = HashSet::new();
    for possible_anagram in possible_anagrams {
        let mut possible: Vec<_> = possible_anagram.to_lowercase().chars().collect();
        if base.eq(&possible) {
            continue;
        }
        possible.sort_unstable();
        if sorted_base.eq(&possible) {
            result.insert(*possible_anagram);
        }
    }

    result
}
