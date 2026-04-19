use std::fmt::Display;

#[derive(Debug, PartialEq)]
pub struct Clock {
    hours: i32,
    minutes: i32,
}

impl Display for Clock {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.write_fmt(format_args!("{:0>2}:{:0>2}", self.hours, self.minutes))
    }
}

impl Clock {
    fn normalize(hours: i32, minutes: i32) -> (i32, i32) {
        let (hours, minutes) = if minutes < 0 {
            (
                hours + (minutes / 60 - 1 + (60 + minutes % 60) / 60),
                (60 + minutes % 60) % 60,
            )
        } else {
            (hours + minutes / 60, minutes % 60)
        };
        let hours = if hours < 0 {
            (24 + hours % 24) % 24
        } else {
            hours % 24
        };
        (hours, minutes)
    }

    pub fn new(hours: i32, minutes: i32) -> Self {
        let (hours, minutes) = Clock::normalize(hours, minutes);
        Self { hours, minutes }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        let (hours, minutes) = Clock::normalize(self.hours, self.minutes + minutes);
        Self { hours, minutes }
    }
}
