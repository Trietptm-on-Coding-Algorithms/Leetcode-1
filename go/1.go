func twoSum(nums []int, target int) []int {
	size := len(nums)
	result := make([]int, 2)
	tables := make(map[int]int)

	for i := 0; i < size; i++{
		need := target - nums[i]

		if _, exits := tables[need]; exits {
			result[0], result[1] = tables[need], i
			return result
		}

		tables[nums[i]] = i
	}

	return result
}
