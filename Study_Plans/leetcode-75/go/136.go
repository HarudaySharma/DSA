package main

func singleNumber(nums []int) int {
	var singleNum int = 0
	for i := 0; i < len(nums); i++ {
		singleNum ^= nums[i]
	}

	return singleNum
}
