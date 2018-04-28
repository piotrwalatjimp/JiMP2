//
// Created by Piotrek on 28.04.2018.
//

#include <string>
#include <vector>
#include <memory>
using ::std::string;
using ::std::vector;
using ::std::pair;
using ::std::make_pair;
using ::std::unique_ptr;
using ::std::make_unique;

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

namespace utility {

    class IterableIterator {
    public:

        virtual pair<int, string> Dereference()const = 0;
        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const unique_ptr<IterableIterator> &other)const = 0;
        ~IterableIterator() = default;

        vector<int>::const_iterator left;
        vector<string>::const_iterator right;
    };

    class ZipperIterator : public IterableIterator {
    public:

        explicit ZipperIterator(vector<int>::const_iterator left_begin,
                                vector<string>::const_iterator right_begin,
                                vector<int>::const_iterator left_end,
                                vector<string>::const_iterator right_end);
        explicit ZipperIterator(vector<int>::const_iterator left,
                                vector<string>::const_iterator right);

        ~ZipperIterator() = default;
        pair<int, string> Dereference()const override;
        IterableIterator &Next() override;
        bool NotEquals(const unique_ptr<IterableIterator> &other)const override;

    };

    class IterableIteratorWrapper {
    public:
        explicit IterableIteratorWrapper(unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();

    private:
        unique_ptr<IterableIterator> iterator;
    };

    class Iterable {
    public:

        virtual unique_ptr<IterableIterator> ConstBegin() const =0;
        virtual unique_ptr<IterableIterator> ConstEnd() const =0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;

        ~Iterable() = default;

        pair<vector<int>, vector<string>> other_pair;
    };

    class Enumerate: public Iterable
    {
    public:

        explicit Enumerate(vector<string> vs);
        unique_ptr<IterableIterator> ConstBegin() const override;
        unique_ptr<IterableIterator> ConstEnd()const override;

    };

    class Zipper : public Iterable {
    public:
        Zipper(vector<int> vi, vector<string> vs);
        unique_ptr<IterableIterator> ConstBegin()const override;
        unique_ptr<IterableIterator> ConstEnd()const override;
    };

    class Product : public Iterable {
    public:
        Product(vector<int> vi, vector<string> vs);
        virtual unique_ptr<IterableIterator> ConstBegin()const override;
        virtual unique_ptr<IterableIterator> ConstEnd() const override;
    };


}
#endif //JIMP_EXERCISES_ITERABLE_H