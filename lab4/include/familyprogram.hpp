#ifndef FAMILYPROGRAM_HPP
#define FAMILYPROGRAM_HPP

class FamilyProgram
{
  private:
    class Ancestor **familyMemebrs = nullptr;
    int size = 0;
    int capacity = 0;

    void expandMembers();
    void addMember();

  public:
    FamilyProgram() = default;
    ~FamilyProgram();

    void addFamilyMember();
    void showAllMembers() const;
    void clear();
    void run();
};

#endif