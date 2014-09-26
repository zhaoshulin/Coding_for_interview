class Solution{
	// 111222333444 => 1234
	// so, 'smaller' is used to index the most-left 1
	// and 'bigger' is used to index the most-right 2
	public:
		int removeDuplicates(int A[], int n)
		{
			int bigger, smaller;

			if(n == 0)
				return 0;

			smaller = 0;
			for(bigger = 1; bigger < n; bigger ++)
			{
				if(A[bigger] != A[smaller])
					A[++ smaller] = A[bigger];
			}

			return ++smaller;
		}
};
