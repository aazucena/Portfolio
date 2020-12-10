#ifndef DEPENDENCYMANAGER_H_INCLUDED
#define DEPENDENCYMANAGER_H_INCLUDED

class DependencyManager {
public:
    static void registerType(const std::type_info*, const std::type_info*);
    static void* create(std::type_info const*);
};

#endif // DEPENDENCYMANAGER_H_INCLUDED
