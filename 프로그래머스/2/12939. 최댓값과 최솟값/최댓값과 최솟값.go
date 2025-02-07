import (
    "fmt"
    "strings"
    "sort"
    "strconv"
)

func solution(s string) string {
    strs := strings.Split(s, " ")
    ints := make([]int, len(strs))
    for i, str := range strs {
        ints[i], _ = strconv.Atoi(str)
    }
    sort.Ints(ints)
    return fmt.Sprintf("%d %d", ints[0], ints[len(ints) - 1])
}