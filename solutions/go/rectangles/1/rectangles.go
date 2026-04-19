package rectangles

func Count(grid []string) int {

	checkRectangle := func(row, col, row_end, col_end int) bool {
		for y := row; y <= row_end; y++ {
			left := grid[y][col]
			right := grid[y][col_end]
			if (y == row || y == row_end) && (left != '+' || right != '+') {
				return false
			} else if !(left == '+' || left == '|') || !(right == '+' || right == '|') {
				return false
			}
		}
		for x := col; x <= col_end; x++ {
			top := grid[row][x]
			bottom := grid[row_end][x]
			if (x == col || x == col_end) && (top != '+' || bottom != '+') {
				return false
			} else if !(top == '+' || top == '-') || !(bottom == '+' || bottom == '-') {
				return false
			}
		}
		return true

	}

	total := 0

	for r := range grid {
		for c := range grid[0] {
			if grid[r][c] != '+' {
				continue
			}

			for h := r + 1; h < len(grid); h++ {
				for w := c + 1; w < len(grid[0]); w++ {
					if checkRectangle(r, c, h, w) {
						total++
					}
				}
			}

		}
	}

	return total
}
