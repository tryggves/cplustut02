//
// Created by Tryggve Sørensen on 24/10/2021.
//
#include <iostream>
#include <list>

class FileProvider {
private:
  std::list<std::string> m_file_list;
  std::list<std::string>::const_iterator m_list_iter;

public:
  FileProvider(){
    // emplace_back() is an alternative to push_back()
//        m_file_list.emplace_back("hello_world");
//        m_file_list.emplace_back("src/foo/bar");
//        m_file_list.emplace_back("src/foo/foobar");
    m_file_list.push_back("hello_world"); // NOLINT(modernize-use-emplace)
    m_file_list.push_back("src/foo/bar"); // NOLINT(modernize-use-emplace)
    m_file_list.push_back("src/foo/foobar"); // NOLINT(modernize-use-emplace)

    m_list_iter = m_file_list.cbegin();
  }

  /**
   * Get a file name from the provider. Picks the next file name from the list.
   * If all file names in the list have been returned, the provider will start from
   * the beginning of the list - hence it will always return a file name from the list.
   *
   * @return std::string with path of file name.
   */
  std::string get_next_file() {
    std::string file_path = *m_list_iter;

    // Advance iterator to next element of the list
    ++m_list_iter;

    // Check if we have exhausted the list
    if (m_list_iter == m_file_list.cend()) {
      // Start from beginning of list
      m_list_iter = m_file_list.cbegin();
    }

    return file_path;
  }
};


int main() {
  std::cout << "===========================================================================" << std::endl;
  std::cout << "== List example" << std::endl;
  std::cout << "===========================================================================" << std::endl;

  std::cout << "\nCreate file list...\n";
  FileProvider fileProvider;
  std::cout << "Next file: " << fileProvider.get_next_file() << std::endl;
  std::cout << "Next file: " << fileProvider.get_next_file() << std::endl;
  std::cout << "Next file: " << fileProvider.get_next_file() << std::endl;
  std::cout << "Next file: " << fileProvider.get_next_file() << std::endl;
  std::cout << "Next file: " << fileProvider.get_next_file() << std::endl;
  std::cout << "Next file: " << fileProvider.get_next_file() << std::endl;
  std::cout << "Next file: " << fileProvider.get_next_file() << std::endl;
  std::cout << "Next file: " << fileProvider.get_next_file() << std::endl;

}