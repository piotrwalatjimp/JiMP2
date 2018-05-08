//
// Created by Piotrek on 28.04.2018.
//
#include "Iterable.h"

namespace utility {
    ZipperIterator::ZipperIterator(vector<int>::const_iterator left_begin, vector<string>::const_iterator right_begin,
                                   vector<int>::const_iterator left_end, vector<string>::const_iterator right_end) {
        this->left = left_begin;
        this->right = right_begin;
    }

    pair<int, string> ZipperIterator::Dereference() const {
        return make_pair(*(this->left), *(this->right));
    }

    IterableIterator& ZipperIterator::Next() {
        this->left++;
        this->right++;
        return *this;
    }

    bool ZipperIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
        return(this->left != other->left || this->right != other->right);
    }

    ZipperIterator::ZipperIterator(vector<int>::const_iterator left, vector<string>::const_iterator right) {
        this->left = left;
        this->right = right;
    }

    IterableIteratorWrapper::IterableIteratorWrapper(unique_ptr<IterableIterator> iterator) {
        this->iterator = move(iterator);
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
        return this->iterator->NotEquals(other.iterator);
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*() {
        return this->iterator->Dereference();
    }

    IterableIteratorWrapper& IterableIteratorWrapper::operator++() {
        this->iterator->Next();
        return *this;
    }

    Zipper::Zipper(vector<int> vi, vector<string> vs) {
        if(vi.size() > vs.size())
            for(auto i=vs.size(); i<vi.size(); i++)
                vs.emplace_back(vs.back());
        else
            for(auto i=vi.size(); i<vs.size(); i++)
                vi.emplace_back(vi.back());
        other_pair = make_pair(vi, vs);
    }

    std::unique_ptr<IterableIterator> Zipper::ConstBegin()const {
        auto zip = ZipperIterator(other_pair.first.begin(), other_pair.second.begin());

        return make_unique<ZipperIterator>(zip);

    }

    unique_ptr<IterableIterator> Zipper::ConstEnd() const {
        auto z = ZipperIterator(other_pair.first.end(), other_pair.second.end());

        return make_unique<ZipperIterator>(z);
    }

    IterableIteratorWrapper Iterable::begin() const {
        return IterableIteratorWrapper{ConstBegin()};
    }

    IterableIteratorWrapper Iterable::end() const {
        return IterableIteratorWrapper{ConstEnd()};
    }

    Enumerate::Enumerate(vector<string> vs) {
        auto vi = vector<int>();
        for(int i=0; i<vs.size(); i++)
            vi.push_back(i+1);

        other_pair = make_pair(vi, vs);
    }

    unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
        auto z = ZipperIterator(other_pair.first.begin(), other_pair.second.begin());

        return make_unique<ZipperIterator>(z);
    }

    unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
        auto z = ZipperIterator(other_pair.first.end(), other_pair.second.end());

        return make_unique<ZipperIterator>(z);
    }

    Product::Product(vector<int> vi, vector<string> vs) {
        auto vi_ = vector<int>();
        auto vs_ = vector<string>();

        for(auto v : vi)
            for(auto t : vs) {
                vi_.emplace_back(v);
                vs_.emplace_back(t);
            }

        other_pair = make_pair(vi_, vs_);
    }

    unique_ptr<IterableIterator> Product::ConstBegin() const {
        auto z = ZipperIterator(other_pair.first.begin(), other_pair.second.begin());

        return make_unique<ZipperIterator>(z);
    }

    unique_ptr<IterableIterator> Product::ConstEnd() const {
        auto z = ZipperIterator(other_pair.first.end(), other_pair.second.end());

        return make_unique<ZipperIterator>(z);
    }
}