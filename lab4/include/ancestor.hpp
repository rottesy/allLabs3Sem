#ifndef ANCESTOR_HPP
#define ANCESTOR_HPP

class Ancestor
{
  private:
    char *humanName = nullptr;

  protected:
    [[nodiscard]] const char *getName() const;

  public:
    explicit Ancestor(const char *name);
    virtual ~Ancestor();
    virtual void print() const = 0;
};

#endif