#include <iostream>
#include <string>
#include <algorithm>
// #include <vector>
using namespace std;

// ���ű��д�����ʹ�õ���Щ˼��
// ����ֱ��ʹ�� next_permutation
/* ���� next_permutation �������亯��ԭ��Ϊ��
    #include <algorithm>
    bool next_permutation(iterator start,iterator end)
����ǰ���в�������һ������ʱ����������false�����򷵻�true */

// �˷���δ�ı�ԭ�ַ�����Ҫ���κδ���ʱ����else�⼴�ɣ��ظ��ַ���������д����ظ���
void StrAll(string str, int start, int end)     //ȫ���еݹ鷨(���ֵ���)  
{
    if (end <= 1)
        return ;
    else if(start >= end) {
        for (int i = 0; i < end; i++)
            cout << str[i];
        cout << endl;   
    }
    else {
        for (int i = start; i < end; i++) {
            swap(str[start], str[i]);
            StrAll(str, start+1, end);
            swap(str[i], str[start]);
        }
    }
}

// �˷���ʹ�������ã�ÿ�����л�ı�ԭ�ַ�����ʹ�ø�������������ظ��ַ����ظ����� ���Ƽ���
bool CalcAllPermutation(string& perm, int num){   //ȫ�����ֵ���
    
    int i, k;
    //���ҵ�������������ң�һ���������λλ��i��x = ai   (˵��֮���һ���ǽ��� ֮��ķ�ת�Ϳɱ�Ϊ����)
    for (i = num - 2; i>=0 && perm[i] >= perm[i + 1]; --i) ;
    if (i < 0)
        return false;

    //���ҵ������е�iλ�ұ����һ����ai ���λ��j��y = aj
    for (k = num - 1; (perm[k] <= perm[i]); --k) ;

    //�۽���x��y
    swap(perm[i], perm[k]);
    //�ܰѵ�(i+ 1)λ�����Ĳ��ַ�ת
    reverse(perm.begin() + i + 1, perm.end());
    cout << perm << endl;
    return true;
}

int main ()
{
    string str;
    cin >> str;     //����һ�����ظ����ַ���

    // �ݹ鷨
    // cout << "ȫ������Ϊ��" << endl;
    // cout << str << " size :" << str.size() << endl;
    // StrAll(str, 0, str.size());

    // �ֵ䷨
    sort(str.begin(), str.end());
    cout << str << endl;
    while ( CalcAllPermutation(str, str.size()) ) ;

    return 0;
}