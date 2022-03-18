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
    m_file_list.push_back("payloads/speed_change_event/1588561058.orca.speed_change.pb"); // NOLINT(modernize-use-emplace)
    m_file_list.push_back("payloads/steer/1611102380.orca.steer.pb"); // NOLINT(modernize-use-emplace)
    m_file_list.push_back("payloads/turn/1611184023.orca.turn.pb"); // NOLINT(modernize-use-emplace)

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

  std::cout << "Get the message type from file name:" << std::endl;
  std::string pb_filename = fileProvider.get_next_file();
  // Get the payload message type from the file name
  // payloads/speed_change_event/1588561058.orca.speed_change.pb
  std::string base_filename = pb_filename.substr(pb_filename.find_last_of("/\\")+1);
  size_t first_dot = base_filename.find_first_of(".");
  size_t last_dot = base_filename.find_last_of(".");
  std::string msg_type = base_filename.substr(first_dot + 1,
                                              last_dot - first_dot -1);
  std::cout << "Message type: " << msg_type << std::endl;

}