// small root macro to check for zombie file since pyroot crashes when
// f.IsZombie() is called on an actual zombie
bool CheckForZombie(char* in_file_name)
{
  TFile f(in_file_name);
  if (f.IsZombie()) return true;
  return false;
}
