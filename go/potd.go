package main

import (
	"fmt"
	"strconv"
	"strings"
)


func getNumber(s string) string {
    var sb strings.Builder

    for _, ch := range s {
        sb.WriteString(fmt.Sprintf("%d", ch - 'a' + 1))
    }
    
    return sb.String()
}

func getLucky(s string, k int) int {
    res := "";
    res = getNumber(s);

    for k != 0 {
        num := 0;
        for _, dig := range res {
            num += int(dig - '0')
        }
        res = strconv.Itoa(num)
        k--
    }

    n, _ := strconv.Atoi(res)
    return n
}

