#include "state.h"
#include <vector>
int main()
{
    Work emergencyProjects;
    vector<State*> vec_states;
    vec_states.push_back(new ForenoonState());
    vec_states.push_back(new NoonState());
    vec_states.push_back(new AfternoonState());
    vec_states.push_back(new EveningState());
    vec_states.push_back(new SleepingState());
    for(int i=0;i<vec_states.size();i++)
    {

        emergencyProjects.SetState(vec_states[i]);//小心删除的元素，不能再使用
        emergencyProjects.WorkProgram();
    }
    vec_states.clear();

    return 0;
}