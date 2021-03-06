#pragma once

#include "GuiComponent.h"
#include "components/MenuComponent.h"
#include "components/BusyComponent.h"

#include <boost/thread.hpp>

class GuiThemeInstall : public GuiComponent {
public:
  //  GuiThemeInstall(Window *window, std::string theme);
    GuiThemeInstall(Window *window, char *theme);

    virtual ~GuiThemeInstall();

    void render(const Transform4x4f &parentTrans) override;

    bool input(InputConfig *config, Input input) override;

    std::vector<HelpPrompt> getHelpPrompts() override;

    void update(int deltaTime) override;

private:
    BusyComponent mBusyAnim;
    bool mLoading;
    int mState;
    std::pair<std::string, int> mResult;

    std::string mThemeName;
    
    boost::thread *mHandle;

    void onInstallError(std::pair<std::string, int>);

    void onInstallOk();

    void threadTheme();

};

