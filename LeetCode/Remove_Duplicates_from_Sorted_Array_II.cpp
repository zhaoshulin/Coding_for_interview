class Solution{
	public:
		int removeDuplicates(int A[], int n)
		{
			if(n < 2) 
				return n;

			// 11222233 then the middle 22 will skip data-copying
			// so we find out which position can be skiped.
			int to = 0;
			for(int from = 0; from < n; from ++)
			{
				if(from > 0 && from < n-1; A[from] == A[from-1] && A[from] == A[from+1])
					continue;

				A[to] = A[from];
			}

			return to;
		}
};
