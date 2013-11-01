#ifndef BBBUILDCONFIGURATION_HPP_INCLUDED
#define BBBUILDCONFIGURATION_HPP_INCLUDED

// Qt Creator
#include <projectexplorer/buildconfiguration.h>
// Qt
#include <QList>
#include <QString>

namespace BoostBuildProjectManager {
namespace Internal {

class BuildConfiguration : public ProjectExplorer::BuildConfiguration
{
    Q_OBJECT

    friend class BuildConfigurationFactory;

public:
    explicit BuildConfiguration(ProjectExplorer::Target* parent);

    ProjectExplorer::NamedWidget* createConfigWidget();

    BuildType buildType() const;

protected:
    BuildConfiguration(ProjectExplorer::Target* parent, BuildConfiguration* source);
    BuildConfiguration(ProjectExplorer::Target* parent, Core::Id const id);

signals:

public slots:

};

class BuildConfigurationFactory : public ProjectExplorer::IBuildConfigurationFactory
{
    Q_OBJECT

public:
    explicit BuildConfigurationFactory(QObject* parent = 0);

    int priority(ProjectExplorer::Target const* parent) const;
    int priority(ProjectExplorer::Kit const* k, QString const& projectPath) const;

    QList<ProjectExplorer::BuildInfo*>
    availableBuilds(ProjectExplorer::Target const* parent) const;

    QList<ProjectExplorer::BuildInfo*>
    availableSetups(ProjectExplorer::Kit const* k, QString const& projectPath) const;

    ProjectExplorer::BuildConfiguration*
    create(ProjectExplorer::Target const* parent,
           ProjectExplorer::BuildInfo const* info) const;

    bool
    canClone(ProjectExplorer::Target const* parent,
             ProjectExplorer::BuildConfiguration* source) const;

    AutotoolsBuildConfiguration*
    clone(ProjectExplorer::Target* parent, ProjectExplorer::BuildConfiguration* source);

    bool canRestore(ProjectExplorer::Target const* parent, QVariantMap const& map) const;

    AutotoolsBuildConfiguration*
    restore(ProjectExplorer::Target *parent, QVariantMap const& map);

private:
    bool canHandle(ProjectExplorer::Target const* target) const;
};

} // namespace Internal
} // namespace BoostBuildProjectManager

#endif // BBBUILDCONFIGURATION_HPP_INCLUDED