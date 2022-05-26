
/*
 * All of your code goes in here. You need to finish these functions.
 */


int hf_max(int x, int y) {
	if (x > y) {
		return x;
	}
	
	if (y > x) {
		return y;
	}

	else {
		return x;
	}
}


int hf_sum(int x, int y) {
	if (y > 0) {
		return(x + y);
	}

	else {
		return x;
	}
}


int hf_negative_count(int x, int y) {
	if (y < 0) {
		return(x + 1);
	}

	else {
		return x;
	}
}


int maximum(int *nums, int len) {
	int max = nums[0];
	for (int i = 0; i < len; i++) {
		int check = nums[i];
		if (check > max) {;
			max = check;
		}
	}
	return max;  
}


int sum_positive(int *nums, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		int check = nums[i];
		if (check > 0) {
			sum = sum + check;
		}
	}
	return sum;
}


int reduce(int *nums, int len, int (*f)(int,int), int initial) {
	for (int i = 0; i < len; i++) {
		initial = f(initial, nums[i]);
	}
        return initial;
}


int maximum_with_reduce(int *nums, int size) {
	int value = reduce(nums, size, hf_max, nums[0]);
        return value;
}


int sum_positive_with_reduce(int *nums, int size) {
	int value = reduce(nums, size, hf_sum, 0);
        return value;
}


int count_negative_with_reduce(int *nums, int size) {
	int value = reduce(nums, size, hf_negative_count, 0);
        return value;
}







