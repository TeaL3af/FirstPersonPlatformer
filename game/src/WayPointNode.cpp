#include "WayPointNode.h"

#include "App.h"
#include "ResourceManager.h"
#include "Mesh.h"
#include "Renderer.h"
#include "CuboidShape.h"
#include "Collider.h"

#include <glm/gtc/matrix_transform.hpp>

WayPointNode::WayPointNode(App* app, std::vector<float> origin) : PersistantNode(app, GAME_RENDER_GEOMETRY)
{
    mOrigin = origin;
    mTransform = glm::scale(glm::mat4(1.0f), glm::vec3(0.2f));
    mTransform = glm::translate(glm::mat4(1.0f), glm::vec3(float(mOrigin[0]), float(mOrigin[1]+0.5f), float(mOrigin[2]))) * mTransform;
    mMesh = mApp->getResourceManager()->loadMeshFromObj("mesh/waypoint.obj", mApp->getResourceManager()->getProgram("generic_mesh"));

    CuboidShape* triggerArea = new CuboidShape(-1.0f, 0.0f, -1.0f, 2.0f, 1.0f, 2.0f);
    addCollider(new Collider(triggerArea, 0, this, GAME_COLLISION_TRIGGER, GAME_COLLISION_PLAYER));
}

WayPointNode::~WayPointNode()
{
    //dtor
}

std::vector<float> WayPointNode::getOrigin()
{
    return mOrigin;
}

void WayPointNode::simulateSelf(GLdouble deltaTime)
{

}

void WayPointNode::renderSelf()
{
    glm::mat4 MVP = mApp->getRenderer()->getProjectionMatrix() * mApp->getRenderer()->getViewMatrix() * mApp->getRenderer()->currentMatrix();
    glm::mat3 normal = glm::mat3(mApp->getRenderer()->currentMatrix());
    mMesh->render(MVP, normal);
}

void WayPointNode::onCollision(CollisionEvent event)
{
    mApp->reachedEndOfLevel();
}
