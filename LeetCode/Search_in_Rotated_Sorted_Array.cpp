class Solution{
	public:
		int search(int A[], int n, int target)
		{
			//only one of the two sets: [first, mid] and [mid, last) is sorted, and I can only wipe off the sorted set.
			//so, we find out which set is sorted.
			if(n == 0)
				return -1;

			int first = 0;
			int last = n;

			while(first < last)
			{
				int mid = (first + last) / 2;
				if(A[mid] == target)
					return mid;

				if(A[first] <= A[mid]) //[first, mid] is sorted
				{
					if(A[first] <= target && target < A[mid])
						last = mid;
					else
						first = mid + 1;
				}
				else // [mid, last) is sorted
				{
					if(A[mid] < target && target <= A[last-1])
						first = mid + 1;
					else
						last = mid;
				}
			}

			return -1;
		}
}
