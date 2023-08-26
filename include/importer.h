#include "structs.h"
#include "bvh.hpp"
#include "helper.hpp"
#include <queue>
namespace fs = std::filesystem;

class PImporter{
    PImporter();
    ~PImporter();

    // Skinned mesh class

    bool DoTheImportThing(const std::string& pFile, PrincipiaModel& m, PrincipiaSkeleton& s, bool triangulate);

    bool WritePEModel(PrincipiaModel& m, std::string fn);
    bool WriteSkeleton(PrincipiaSkeleton& s, std::string fn);


    PrincipiaModel ReadPEModel(const char* pFile);
    bool LoadDirectory(std::string directory, bool triangulate);


    ///////////////ANIMATION STUFF///////////////////////
    struct tempDataStruct {
        std::vector<Joint> skeletonJoints;

        std::vector<int> parentIndexes;
        std::vector<aiNode*> confirmedNodes;
        std::unordered_map<std::string, int> nodeIndexes;
        std::string skelename;
        std::vector<aiBone*> bones;
    };

    bool LoadBones(const aiScene* scene, tempDataStruct& tds);
    ///////////////ANIMATION STUFF///////////////////////

    bool hasAnim = false;

    int main();
};
