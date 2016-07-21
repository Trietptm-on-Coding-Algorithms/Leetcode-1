package LeetCode

func lengthOfLongestSubstring(s string) int {
	size := len(s)
	var tables [26]int

	pre, cur, maxSub := -1, 0, -1

	for i := 0; i < 256; i++ {
		tables[i] = -1
	}

	for ; cur < size; cur++ {
		key := tables[s[cur]-'a']

		if tables[key] == -1 {
			tables[key] = cur
		} else {
			if sub := cur - pre - 1; sub > maxSub {
				maxSub = sub
			}
			if tables[key] > pre {
				pre = tables[key]
			}
			tables[key] = cur
		}
	}

	if sub := cur - pre - 1; sub > maxSub {
		maxSub = sub
	}

	return maxSub
}
