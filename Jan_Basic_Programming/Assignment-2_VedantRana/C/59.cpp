#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector(vector<T> v)
{
   cout << "[";
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << ", ";
   }
   cout << "]" << endl;
}

template <typename T>
void print_vector(vector<vector<T>> v)
{
   cout << "[";
   for (int i = 0; i < v.size(); i++)
   {
      cout << "[";
      for (int j = 0; j < v[i].size(); j++)
      {
         cout << v[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]" << endl;
}

class Solution
{
public:
   vector<string> fullJustify(vector<string> &a, int b)
   {
      vector<string> result;
      int i, j;
      for (i = 0; i < a.size(); i = j)
      {
         int width = 0;
         for (j = i; j < a.size() && width + a[j].size() + j - i <= b; j++)
         {
            width += a[j].size();
         }
         int space = 1;
         int extra = 0;
         if (j - i != 1 && j != a.size())
         {
            space = (b - width) / (j - i - 1);
            extra = (b - width) % (j - i - 1);
         }
         string line(a[i]);
         for (int k = i + 1; k < j; k++)
         {
            line += string(space, ' ');
            if (extra-- > 0)
            {
               line += " ";
            }
            line += a[k];
         }
         int x = line.size();
         line += string(b - x, ' ');
         result.push_back(line);
      }
      return result;
   }
};

int main()
{
   vector<string> v = {"I", "love", "coding.", "here", "we", "will", "write", "some", "program"};
   Solution ob;
   print_vector(ob.fullJustify(v, 16));

   return 0;
}
