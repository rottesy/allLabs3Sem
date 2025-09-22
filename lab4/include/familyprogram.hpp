#ifndef FAMILYPROGRAM_HPP
#define FAMILYPROGRAM_HPP

class FamilyProgram
{
  private:
    class Ancestor **familyMemebrs = nullptr;
    int size = 0;
    int capacity = 1;

    void expandMembers();
    void addMember();

  public:
    FamilyProgram() = default;
    ~FamilyProgram();

    FamilyProgram(const FamilyProgram&) = delete;
    FamilyProgram& operator=(const FamilyProgram&) = delete;

    void addFamilyMember();
    void showAllMembers() const;
    void clear();
    void run();
};

#endif