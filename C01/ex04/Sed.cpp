#include "Sed.hpp"

Sed::Sed(){return;}

Sed::Sed(std::string p, std::string s, std::string r) : file_path(p), str_search(s), str_replace(r)
{
    if (str_search.empty() || str_replace.empty())
    {
        std::cout << "string invalid" << std::endl;
        exit(1);
    }
}

Sed::~Sed(){return;}

void Sed::like_replace(void)
{
    std::fstream file_to_read(file_path.c_str());
    
    //check de l'ouverture du fichier source
    if (file_to_read.fail())
    {
        std::cout << "File cannot be opened" << std::endl;
        exit(1);
    }
    //check si le fichier est vide
    if (file_to_read.peek() == file_to_read.eof())
    {
        file_to_read.close();
        std::cout << "File empty" << std::endl;
        exit(0);
    }
    //creation du nouveau fichier
    std::string new_path = file_path + ".replace";
    std::fstream file_to_write(new_path.c_str(), std::fstream::out);
    //verification de la creation et ouverture
    if (file_to_write.fail())
    {
        file_to_read.close();
        std::cout << "File cannot be opened or are not be created" << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(file_to_read, line))
    {
        std::size_t target = line.find(str_search);
        if (target != std::string::npos)
        {
            while(target != std::string::npos)
            {
                file_to_write.write(line.c_str(), target); //copie jusqu'a target
                file_to_write.write(str_replace.c_str(), str_replace.length()); //copie du remplacement
                line = line.substr(target); //reformatage de la chaine jusqu'a la target
                line = line.substr(str_search.length()); //reformatage de la chaine pour passer le morceau a remplace
                target = line.find(str_search);
            }
            if (file_to_read.eof())
                file_to_write << line;
            else
                file_to_write << line << std::endl;
        }
        else
        {
            if (file_to_read.eof())
                file_to_write << line;
            else
                file_to_write << line << std::endl;
        }
    }
    file_to_read.close();
    file_to_write.close();
}
