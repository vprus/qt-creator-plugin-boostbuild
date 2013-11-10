#include "bbproject.hpp"
#include "bbprojectfile.hpp"
#include "bbprojectmanagerconstants.hpp"
#include "bbutility.hpp"

namespace BoostBuildProjectManager {
namespace Internal {

ProjectFile::ProjectFile(Project* project, QString const& fileName)
    : Core::IDocument(project)
    , project_(project)
{
    Q_ASSERT(!fileName.isEmpty());

    setFilePath(fileName);

    BBPM_QDEBUG(fileName);
}

bool ProjectFile::save(QString* errorString, QString const& fileName, bool autoSave)
{
    Q_UNUSED(errorString);
    Q_UNUSED(fileName);
    Q_UNUSED(autoSave);

    BBPM_QDEBUG("TODO");
    return false;
}

QString ProjectFile::defaultPath() const
{
    BBPM_QDEBUG("TODO");
    return QString();
}

QString ProjectFile::suggestedFileName() const
{
    return QString();
}

QString ProjectFile::mimeType() const
{
    BBPM_QDEBUG("TODO");
    return QLatin1String(Constants::MIMETYPE_JAMFILE);
}

bool ProjectFile::isModified() const
{
    return false;
}

bool ProjectFile::isSaveAsAllowed() const
{
    BBPM_QDEBUG("TODO");
    return false;
}

bool ProjectFile::reload(QString* errorString, ReloadFlag flag, ChangeType type)
{
    Q_UNUSED(errorString);
    Q_UNUSED(flag);
    Q_UNUSED(type);

    BBPM_QDEBUG("TODO");
    return false;
}

} // namespace Internal
} // namespace AutotoolsProjectManager
