#include "bits/stdc++.h"
using namespace std;

//
// BHENDIIIIIIIIIIIIIIII
//

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back

// void check(vector<int> arr, vector<pair<int, int>> operations)
// {
// 	cout << "Original array: ";
// 	for (auto i : arr)
// 	{
// 		cout << i << " ";
// 	}
// 	cout << endl;
// 	for (auto i : operations)
// 	{
// 		arr[i.first - 1] += arr[i.second - 1];
// 	}
// 	cout << "Modified array: ";
// 	for (auto i : arr)
// 	{
// 		cout << i << " ";
// 	}
// 	cout << endl;
// }

int main()
{
	ll t;
	cin >> t;
	int testCase = 1;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		// if (testCase == 67)
		// {
		// 	cout << "n:" << n << "|arr:";
		// 	for (auto i : v)
		// 	{
		// 		cout << i << "|";
		// 	}
		// }
		// testCase++;
		// cout << endl;

		int cnt = 0;

		int flag = 0;
		int positivePresent = (v[n - 1] > 0);
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i] > v[i + 1])
			{
				flag = 1;
			}
			if (v[i] > 0)
			{
				positivePresent = 1;
			}
		}
		if (!flag)
		{
			cout << 0 << endl;
			continue;
		}

		cout << 5 + (2 * (n - 1)) << endl;

		// cout << 50 << endl;
		if (!positivePresent)
		{
			ll mini = *min_element(all(v));
			ll minIndex = -1;
			// vector<pair<short, short>> operations;
			for (int i = 0; i < n; i++)
			{
				if (v[i] == mini)
				{
					minIndex = i;
					break;
				}
			}
			int cnt1 = 5;
			while (cnt1--)
			{
				v[minIndex] += v[minIndex];
				// operations.pb({minIndex + 1, minIndex + 1});
				cout << minIndex + 1 << " " << minIndex + 1 << endl;
				mini = v[minIndex];
			}

			for (int i = n - 2; i >= 0; i--)
			{
				// if (v[i] > v[i + 1])
				// {
				cnt1 = 2;
				while (cnt1--)
				{
					v[i] += v[minIndex];
					// operations.pb({i + 1, minIndex + 1});
					cout << i + 1 << " " << minIndex + 1 << endl;
					if (v[i] < mini)
					{
						mini = v[i];
						minIndex = i;
					}
				}
				// }
			}
			// while (cnt < 50)
			// {
			// 	cout << 1 << " " << n << endl;
			// 	cnt++;
			// }
			// cout << operations.size() << endl;
			// for (auto i : operations)
			// {
			// 	cout << i.first << " " << i.second << endl;
			// }

		} // IF END
		else
		{
			ll maxi = *max_element(all(v));
			// cout << "maxi: " << maxi << endl;
			ll maxIndex = -1;
			// vector<pair<short, short>> operations;
			for (int i = 0; i < n; i++)
			{
				if (v[i] == maxi)
				{
					maxIndex = i;
					break;
				}
			}
			int cnt1 = 5;
			while (cnt1--)
			{
				v[maxIndex] += v[maxIndex];
				maxi = v[maxIndex];
				// operations.pb({maxIndex + 1, maxIndex + 1});
				cout << maxIndex + 1 << " " << maxIndex + 1 << endl;
			}
			for (int i = 1; i < n; i++)
			{
				// if (v[i] < v[i - 1])
				// {
				cnt1 = 2;
				while (cnt1--)
				{
					v[i] += maxi;
					// operations.pb({i + 1, maxIndex + 1});
					cout << i + 1 << " " << maxIndex + 1 << endl;
					if (v[i] > maxi)
					{
						maxi = v[i];
						maxIndex = i;
					}
				}
				// }
			}
			// ll indexFirstPositive = -1;
			// for (int i = 0; i < n; i++)
			// {
			// 	if (v[i] >= 0)
			// 	{
			// 		indexFirstPositive = i;
			// 		break;
			// 	}
			// }
			// while (cnt < 50)
			// {
			// 	cout << n << " " << indexFirstPositive + 1 << endl;
			// 	cnt++;
			// }

			// check(v, operations);

			// cout << operations.size() << endl;
			// for (auto i : operations)
			// {
			// 	cout << i.first << " " << i.second << endl;
			// }

		} // ELSE END

		// cout << "Modified Array: ";
		// for (auto i : v)
		// {
		// 	cout << i << " ";
		// }
		// cout << endl;

		// ll n;
		// cin >> n;
		// ll a[n];
		// ll b[n][2];
		// // vector<vector<ll>> b(n, vector<ll>(2, 0));
		// ll max = -21;
		// ll min = 21;
		// ll maxIndex = 0;
		// ll minIndex = 0;
		// ll flag = 0;
		// ll flag2 = 0;
		// for (ll i = 0; i < n; i++)
		// {
		// 	cin >> a[i];
		// 	if (i > 0 && a[i] != a[i - 1])
		// 	{
		// 		flag = 1;
		// 	}
		// 	if (a[i] > max)
		// 	{
		// 		max = a[i];
		// 		maxIndex = i;
		// 	}
		// 	if (a[i] < min)
		// 	{
		// 		min = a[i];
		// 		minIndex = i;
		// 	}

		// 	if (a[i] > 0)
		// 	{
		// 		flag2 = 1;
		// 	}
		// }

		// int fflag = 0;
		// for (int i = 0; i < n - 1; i++)
		// {
		// 	if (a[i] > a[i + 1])
		// 	{
		// 		fflag = 1;
		// 		break;
		// 	}
		// }
		// if (!fflag)
		// {
		// 	cout << 0 << endl;
		// 	continue;
		// }

		// ll count = 0;
		// ll bi = 0;
		// if (flag2 == 1)
		// {
		// 	a[n - 1] += a[maxIndex];

		// 	b[bi][0] = n;
		// 	b[bi++][1] = maxIndex + 1;
		// 	count++;
		// }

		// while (a[n - 1] <= max && flag == 1)
		// {
		// 	a[n - 1] += a[maxIndex];
		// 	b[bi][0] = n;
		// 	b[bi++][1] = maxIndex + 1;
		// 	count++;
		// }
		// //		cout<<"End of array: "<<a[n-1]<<endl;
		// ll flag3 = 0;
		// for (ll i = 0; i < n - 1 && flag2 == 1; i++)
		// {
		// 	// cout<<"\n in first for";
		// 	long long int j = 0;
		// 	if (a[i] > a[i + 1])
		// 	{
		// 		for (; j < n;)
		// 		{
		// 			if (a[i + 1] + a[j] >= a[i])
		// 			{
		// 				a[i + 1] += a[j];
		// 				b[bi][0] = i + 2;
		// 				b[bi++][1] = j + 1;
		// 				count++;
		// 				break;
		// 			}
		// 			else if (j == n - 1)
		// 			{
		// 				a[i + 1] += a[j];
		// 				b[bi][0] = i + 2;
		// 				b[bi++][1] = j + 1;
		// 				count++;
		// 				j = 0;
		// 				continue;
		// 			}
		// 			j++;
		// 		}
		// 	}
		// }

		// if (flag2 == 0)
		// {
		// 	a[n - 1] += a[minIndex];

		// 	b[bi][0] = n;
		// 	b[bi++][1] = minIndex + 1;
		// 	count++;

		// 	while (a[n - 1] <= min)
		// 	{
		// 		a[n - 1] += a[minIndex];
		// 		b[bi][0] = n;
		// 		b[bi++][1] = minIndex + 1;
		// 		count++;
		// 	}
		// 	for (ll i = 0; i < n - 1; i++)
		// 	{
		// 		ll j = 0;
		// 		if (a[i] > a[i + 1])
		// 		{
		// 			for (; j < n;)
		// 			{
		// 				if (a[i] + a[j] <= a[i + 1])
		// 				{
		// 					a[i] += a[j];
		// 					b[bi][0] = i + 1;
		// 					b[bi++][1] = j + 1;
		// 					count++;
		// 					break;
		// 				}
		// 				else if (j == n - 1)
		// 				{
		// 					a[i + 1] += a[j];
		// 					b[bi][0] = i + 2;
		// 					b[bi++][1] = j + 1;
		// 					count++;
		// 					j = 0;
		// 					continue;
		// 				}
		// 				j++;
		// 			}
		// 		}
		// 	}
		// }

		// vector<vector<ll>> operations;
		// for (int i = 0; i < count; i++)
		// {
		// 	operations.push_back({b[i][0], b[i][1]});
		// }

		// printModArr(a, operations, n, count);

		// cout << count << endl;
		// for (ll i = 0; i < count; i++)
		// {
		// 	cout << b[i][0] << " " << b[i][1] << endl;
		// }
	}

	return 0;
}
