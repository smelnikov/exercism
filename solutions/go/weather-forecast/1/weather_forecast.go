// Package weather provides basic functionality for tracking the current weather condition for specific location.
package weather

// CurrentCondition stores current weather condition.
var CurrentCondition string

// CurrentLocation stores the name of the location, for which the current weather condition is being reported.
var CurrentLocation string

// Forecast returns formatted string representing the current weather status.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
