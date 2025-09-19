// original class without the verbose output

// template<typename key_t, typename value_t>
// struct Pair
// {
//     key_t key;
//     value_t val;
// };
//
// template <typename key_t, typename value_t>
// class HashMap
// {
// private:
//     std::list< Pair<key_t, value_t> > buckets[16];
//
// public:
//     int hash(const key_t& key)
//     {
//         return std::hash<key_t>{}(key) % 16; // return an index 0-15
//     }
//
//     void add(const key_t& key, const value_t& val)
//     {
//         int bucket_index = hash(key);
//         auto& targeted_list = buckets[bucket_index];
//
//         if (targeted_list.empty())
//         {
//             // list is empty
//             targeted_list.emplace_back(Pair<key_t, value_t>{key, val});
//         }
//         else
//         {
//             for (auto& pair : targeted_list) // if the key already exists in the list, return
//             {
//                 if (key == pair.key)
//                     return;
//             }
//
//             targeted_list.emplace_back(Pair<key_t, value_t>{key, val});
//         }
//     }
//
//     value_t& get(const key_t& key)
//     {
//         int bucket_index = hash(key);
//         auto& targeted_list = buckets[bucket_index];
//
//         // i really dont feel like addressing sad path rn
//         for (auto& pair : targeted_list)
//         {
//             if (key == pair.key)
//                 return pair.val;
//         }
//     }
// };