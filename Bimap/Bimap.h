//
// Created by Mazyad Alabduljaleel on 8/11/15.
//

#ifndef PROJECT_BIMAP_H
#define PROJECT_BIMAP_H

#include <unordered_map>
#include <map>

/** Simple Bimap implementation, with only STL dependency
 */
template <typename KeyType, typename ValueType>
struct Bimap {

    void set(const KeyType& key, const ValueType& value) {

        _normalMap[key] = value;
        _transposeMap[value] = key;
    }

    KeyType& keyForValue(const ValueType &value) {
        return _transposeMap.at(value);
    }

    ValueType& valueForKey(const KeyType &key) {
        return _normalMap.at(key);
    }

    bool removeKey(const KeyType& key) {

        auto has = hasKey(key);
        if (has) {

            auto &value = valueForKey(key);
            _normalMap.erase(key);
            _transposeMap.erase(value);
        }

        return has;
    }

    bool removeValue(const ValueType& value) {

        auto has = hasValue(value);
        if (has) {

            auto &key = keyForValue(value);
            _normalMap.erase(key);
            _transposeMap.erase(value);
        }

        return has;
    }

    bool hasKey(const KeyType& key) const {
        return _normalMap.find(key) != _normalMap.end();
    }

    bool hasValue(const ValueType& value) const {
        return _transposeMap.find(value) != _transposeMap.end();
    }

    unsigned long size() const {
        return _normalMap.size();
    }

    const std::map<ValueType, KeyType>& valueMap() const {
        return _transposeMap;
    };

private:

    std::unordered_map<KeyType, ValueType> _normalMap;
    std::map<ValueType, KeyType> _transposeMap;
};


#endif //PROJECT_BIMAP_H
