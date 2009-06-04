template<class IndexType, class ValueType>
class TSIterator
{
    public:
        ValueType prev() = 0;
        ValueType next() = 0;
        IndexType index() = 0;
        IndexType begin() = 0;
        IndexType end() = 0;
};

