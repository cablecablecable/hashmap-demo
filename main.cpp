#include <iostream>
#include <list>

template<typename key_t, typename value_t>
struct Pair
{
    key_t key;
    value_t val;
};

template <typename key_t, typename value_t>
class HashMap
{
private:
    std::list< Pair<key_t, value_t> > buckets[16];

public:
    int hash(const key_t& key)
    {
        std::cout << key << " hashes to " << std::hash<key_t>{}(key) << ", bucket index " << std::hash<key_t>{}(key) % 16 << " chosen.\n";
        return std::hash<key_t>{}(key) % 16; // return an index 0-15
    }

    void add(const key_t& key, const value_t& val)
    {
        std::cout << "\n(adding pair to hashmap)\nKey: " << key << "  |  Value: " << val << "\n";
        int bucket_index = hash(key);
        auto& targeted_list = buckets[bucket_index];

        if (targeted_list.empty())
        {
            // list is empty
            std::cout << "Bucket's linked list is empty, adding (" << key << ", " << val << ") as a pair.\n";
            targeted_list.emplace_back(Pair<key_t, value_t>{key, val});
        }
        else
        {
            for (auto& pair : targeted_list) // if the key already exists in the list, return
            {
                if (key == pair.key)
                {
                    std::cout << key << " already exists in the list, skipping...\n";
                    return;
                }
            }
            std::cout << "Hash collision! Bucket's list already contains pairs, appending (" << key << ", " << val << ") to the end of the list.\n";
            targeted_list.emplace_back(Pair<key_t, value_t>{key, val});
        }
    }

    value_t& get(const key_t& key)
    {
        std::cout << "\n(getting value from hashmap)\nKey: " << key << "\n";
        int bucket_index = hash(key);
        auto& targeted_list = buckets[bucket_index];

        int nodes_traversed = 0;
        // i really dont feel like addressing sad path rn
        for (auto& pair : targeted_list)
        {
            nodes_traversed++;
            if (key == pair.key)
            {
                std::cout << "Nodes traversed: " << nodes_traversed << "\n";
                return pair.val;
            }
        }
    }
};

int main()
{
    HashMap<std::string, int> employees_ages{};

    employees_ages.add("George", 19);
    std::cout << employees_ages.get("George") << " is the value\n";

    employees_ages.add("George", 5555);

    employees_ages.add("Jill", 77);
    std::cout << employees_ages.get("Jill") << " is the value\n";

}