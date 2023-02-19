#include <iostream>
#include <list>

class AbstractFile
{
protected:
    std::string filename_;
    AbstractFile *parent_;

public:
    explicit AbstractFile(const std::string &filename) : filename_(filename)
    {
        parent_ = nullptr;
    }

    void setParent(AbstractFile *parent)
    {
        parent_ = parent;
    }

    AbstractFile *getParent() const
    {
        return parent_;
    }

    const std::string &getFilename() const
    {
        return filename_;
    }

    virtual void readFile() = 0;

    virtual bool hasChild()
    {
        return false;
    };

    virtual void add(AbstractFile *file)
    {
    }

    virtual void remove(AbstractFile *file)
    {
    }

    virtual ~AbstractFile()
    {
        std::cout << "#del file:" << filename_ << std::endl;
    };
};

class TextFile : public AbstractFile
{
protected:
    std::string text;

public:
    TextFile(const std::string &filename, const std::string &text)
        : AbstractFile(filename), text(text)
    {
    }

    virtual void readFile() override
    {
        std::cout << "=readFile:" << filename_ << "=" << std::endl
                  << "============================" << std::endl
                  << text << std::endl
                  << "============================" << std::endl;
    }
};

class Folder : public AbstractFile
{
protected:
    std::list<AbstractFile *> files_;

public:
    explicit Folder(const std::string &filename) : AbstractFile(filename)
    {
    }

    virtual void readFile() override
    {
        std::cout << "=Folder:" << filename_ << "=" << std::endl;
        if (!hasChild())
        {
            std::cout << "!该文件夹下无文件!" << std::endl;
        }
        for (auto item = files_.begin(); item != files_.end(); ++item)
        {
            (*item)->readFile();
        }
    }

    virtual bool hasChild() override
    {
        return files_.size() > 0;
    }

    virtual void add(AbstractFile *file) override
    {
        file->setParent(this);
        files_.push_back(file);
    }

    virtual void remove(AbstractFile *file) override
    {
        file->setParent(nullptr);
        files_.remove(file);
    }

    virtual ~Folder() override
    {
        for (auto item = files_.begin(); item != files_.end(); ++item)
        {
            delete (*item);
        }
    }
};

int main()
{
    Folder *folder = new Folder("新建文件夹");
    for (int i = 0; i < 20; i++)
    {
        std::string name = "file", text = "hello world ";
        name += std::to_string(i + 1) + ".txt";
        text += std::to_string(i + 1);
        folder->add(new TextFile(name, text));
    }
    folder->readFile();
    delete folder;
    return 0;
}
