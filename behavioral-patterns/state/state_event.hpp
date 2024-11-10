#ifndef __STATE_STATE_EVENT__
#define __STATE_STATE_EVENT__

namespace state
{
class IStateEvent
{
public:
    virtual void Scan() = 0;         // 扫描
    virtual void ScanFinish() = 0;   // 扫描完成
    virtual void Repair() = 0;       // 修复
    virtual void RepairFinish() = 0; // 修复完成
    virtual void Parse() = 0;        // 暂停
    virtual void Abort() = 0;        // 终止
    virtual void Reset() = 0;        // 重置
};
} // namespace state

#endif /* __STATE_STATE_EVENT__ */
