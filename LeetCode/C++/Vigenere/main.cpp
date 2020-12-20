#include <iostream>
#include <vector>
#include <string>

std::vector<char> alphabet = 
{
    'A', 'B', 'C', 'D', 'E', 'F'
};

int get_alpha_number(char c)
{
    for(int i = 0; i < alphabet.size(); ++i)
    {
        if(alphabet[i] == c)
        {
            return i;
        }
    }

    return -1;
}

std::string vigenere_decript(const std::string& cipher, const std::string& key)
{
    std::string output;
    const int n = alphabet.size();

    for(int i = 0; i < cipher.size(); ++i)
    {
        int key_index = i % key.size();
 
        int c = get_alpha_number(cipher[i]);
        int k = get_alpha_number(key[key_index]);
        int m = (c + n - k) % n;

        //std::cout << " C : " << alphabet[c] << " K : " << alphabet[k] << " M : " << alphabet[m] << std::endl;

        output += alphabet[m];
    }

    return output;
}

std::string vigenere_crypt(const std::string& cipher, const std::string& key)
{
    std::string output;
    const int n = alphabet.size();
    std::cout << std::endl;

    for(int i = 0; i < cipher.size(); ++i)
    {
        int key_index = i % key.size();
 
        int c = get_alpha_number(cipher[i]);
        int k = get_alpha_number(key[key_index]);
        int m = (c + k) % n;

        std::cout << " C : " << alphabet[c] << " K : " << alphabet[k] << " M : " << alphabet[m] << std::endl;

        output += alphabet[m];
    }

    return output;
}

int main()
{
    std::cout << "Crypt :" <<  vigenere_crypt("EFFCA", "BCE") << std::endl;
    //std::cout << "Decrypt : " <<  vigenere_decript("BDAAC","BCE") << std::endl;
    return 0;
}
