#ifndef __SPARSE_TABLE__
#define __SPARSE_TABLE__

#include <vector>

namespace Zeus
{
	namespace DataStructure
	{
		/**
			F - is a functional class which implements operations:
			  static T operator(T, T)   - associative, absorbing operation (*)
			  static T neutral()		- returns neutral element E:
				1) a*(b*c) = (a*b)*c;
				2) a*E = E*a = a;
		*/
		template<class T, class F>
		class SparseTable
		{
			const F & func;
			std::vector<std::vector<T> > data;
			const std::vector<T> & inputData;
			int maxPow2;
		public:
			SparseTable( const std::vector<T> & value, const F & funcRef = F() );
			~SparseTable();
			int log2(int x) const;
			T getMin(int left, int right) const;
		};

		template<class T, class F>
		SparseTable<T,F>::SparseTable(const std::vector<T> & value, const F & funcRef)
			: func(funcRef),
			  inputData(value)
		{
			int N = value.size();
			maxPow2 = 0;
			int delta = 2;

			while(N>=delta)
			{
				int delta2 = delta>>1;
				int K = N - delta + 1;
				data.push_back(std::vector<T>());
				data.back().reserve(K);

				const std::vector<T> & prev = maxPow2?data[maxPow2-1]:inputData;

				for(int i=0; i<K; ++i)
					data.back().push_back( func(prev[i], prev[i+delta2]) );

				++maxPow2;
				delta<<=1;
			}
		}

		template<class T, class F>
		SparseTable<T,F>::~SparseTable()
		{
		}

		template<class T, class F>
		int SparseTable<T, F>::log2(int x) const
		{
			int left = 0, right = maxPow2+1;
			while(left<right-1)
			{
				int c = (left+right)>>1;
				if (x >= (1<<c)) left = c;
				else right = c;
			}
			return left;
		}

		template<class T, class F>
		T SparseTable<T, F>::getMin(int left, int right) const
		{
			if(left==right)
				return inputData[left];
			else
			{
				int index = log2(right - left + 1);
				return func(data[index-1][left], data[index-1][right - (1<<index) + 1]);
			}
		}
	}
}

#endif __SPARSE_TABLE__