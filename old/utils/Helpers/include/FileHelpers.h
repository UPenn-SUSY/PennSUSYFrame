#ifndef FileHelpers_h
#define FileHelpers_h

#include <string>

// =============================================================================
bool fileExists(const std::string& file_name);
bool checkFile(const std::string& file_name, bool force_overwrite = false);

#endif
