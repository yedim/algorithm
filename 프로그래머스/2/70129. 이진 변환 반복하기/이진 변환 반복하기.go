import "strconv"

func solution(s string) []int {
    result := []int{0, 0}
    for {
        if s == "1" {
            break
        }
        var cnt int64 = 0
        for _, c := range s {
            if c == '0' {
                result[1] += 1
            } else {
                cnt += 1
            }
        }
        s = strconv.FormatInt(cnt, 2)
        result[0] += 1
    }
    
    return result
}