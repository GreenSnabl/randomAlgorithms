#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::vector;

int atoi(std::string str)
{
    vector<int> vi;
    int res = 0, temp = 1;
    for(char &c : str)
    {
    if(isdigit(c))
    vi.push_back(c-'0');
    else return -1;
    }
    for(int i = 0; i < vi.size(); ++i)
        std::cout << vi[i] << "\n";
    for (int i = 0; i < vi.size(); ++i)
    {
        
        res += temp*vi[vi.size()-1-i];
        temp *=10;
    }
    return res;
}

vector<std::string> getWordVec(std::string input)
{
    vector<std::string> vstr;
    std::ostringstream os;
    std::ifstream ifs;
    ifs.open(input, std::ifstream::in);
    char c = ifs.get();
    while (ifs.good())
    {
        
        while(isalpha(c) || c == '-'){
            os << c;
            c = ifs.get();
        }
        c = ifs.get();
        if(os.str().size() > 0) vstr.push_back(os.str());
        os.str(std::string());
    }
    ifs.close();
    return vstr;
}

void countWords(std::string input)
{
    vector<std::string> vstr = getWordVec(input);
    vector<std::string> vstrclean;
    vector<int> vcnt;
    int cnt = 1;
    std::sort(vstr.begin(), vstr.end());
    for(int i = 0; i < vstr.size()-1; ++i)
    {
        if(vstr[i] != vstr[i+1])
        {
            vstrclean.push_back(vstr[i]);
            vcnt.push_back(cnt);
            cnt = 1;
        }
        if(vstr[i] == vstr[i+1]) ++cnt;
    }
    for (int i = 0; i < vstrclean.size(); ++i)
    {
    std::cout << vcnt[i] << "\t\t||\t\t'" << vstrclean[i] << "'\n";
    }
}


int countStringInFile(std::string inputString, std::string textfile)
{
    std::ostringstream os;
    std::string str = inputString;
    std::ifstream ifs;
    ifs.open (textfile, std::ifstream::in);
    char c = ifs.get();
    while (ifs.good()) {
    os << c; 
    c = ifs.get();
    }
    
    ifs.close();

  std::size_t found = os.str().find(str);
  size_t cnt = 0;
  if (found!=std::string::npos){
    //std::cout << "first '" << str<<"' found at: " << found << '\n';
    ++cnt;
  }
  while(found < os.str().size() - str.size()){
      found=os.str().find(str,found+1);
  if (found!=std::string::npos) ++cnt; //std::cout << "next '"<< str << "' found at: " << found << '\n';
      
  }
  //std::cout << cnt << " '" << str << "' gefunden";
  return cnt;
}


void getLetterCount(std::string textfile)
{
    std::string st = "";
    std::vector<char> alpha;
    for (int i = 0; i < 26; ++i)
        alpha.push_back('A'+i);
    for (int i = 0; i < 26; ++i)
        alpha.push_back('a'+i);
    std::vector<int> count;
    for(int i = 0; i < 52; ++i){
        st = alpha[i];
        count.push_back(countStringInFile(st,textfile));
}
    for(int i = 0; i < 52; ++i)
        std::cout << count[i] << "\t||\t" << alpha[i] << "\n";
}

int euklid(int p, int q)
{
    int r;
    if (q == 0) return p;
    r= p%q;
    euklid(q,r);
}


std::vector<int> insertionSort(std::vector<int> v)
{
    int key, i;
    for (int j = 1; j < v.size(); ++j)
    {
    key = v[j];
    i = j -1;
    while(i >= 0 && v[i] > key)
    {
        v[i+1] = v[i];
        --i;    
    }
    v[i+1] = key;
    }
    return v;
}

std::vector<int> decInsertionSort(std::vector<int> v)
{
    int key, i;
    for(int j = 1; j < v.size(); ++j)
    {
        key = v[j];
        i = j - 1;
        while(i >= 0 && v[i] < key)
        {
            v[i+1] = v[i];
            --i;
        }
        v[i+1] = key;
    }
    return v;
}


int main()
{
    std::vector<int> vec{1,4,6,3,2,7,2,9,10,34,225};
    std::vector<int> v1,v2;
    v1 = insertionSort(vec);
    v2 = decInsertionSort(vec);
    for(int i = 0; i< v1.size(); ++i)
        std::cout << "unsorted:\t" << vec[i] << "\tincreasing sorted:\t" << v1[i] 
                << "\tdecreasing sorted:\t" << v2[i] << "\n";


    
    return 0;
}
