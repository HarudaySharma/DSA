package main

func countSeniors(details []string) int {
    seniorCount := 0

    for _, detail := range details {
        var firstAgeChar byte = detail[len(detail) - 4]
        var secondAgeChar byte = detail[len(detail) - 3]

        if firstAgeChar == '6' && secondAgeChar > '0' {
            seniorCount += 1
        }
        if firstAgeChar > '6' {
            seniorCount += 1
        }
    }

    return seniorCount
}

