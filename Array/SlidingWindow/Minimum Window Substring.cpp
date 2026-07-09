class Solution {
public:
    string minWindow(string s, string t) {
        
        // Two maps 
        // 1) need ---> keep character count in t
        // 2) Track ---> keep character count across window
        unordered_map<char , int> need, Track;
        for(auto character : t){
            need[character]++;
        }
        
        int size = s.length();
        int required = need.size();
        int have = 0, left = 0 , right = 0;
        int minWindow = INT_MAX;
        int start = 0;
        while(right < size){
            Track[s[right]]++;
            if(Track[s[right]] == need[s[right]])
                have++;
            while(required == have){
                if(right - left + 1 < minWindow){
                    minWindow = right - left + 1;
                    start = left;
                }
                
                Track[s[left]]--;
                if(Track[s[left]] < need[s[left]]){
                    have--;
                }
                left++;
            }    
            right++;
        }
        if(minWindow == INT_MAX){
            return "";
        }
        return s.substr(start , minWindow)\;
    }
};
/*
### Complete Algorithm — Minimum Window Substring

---

### Pre-Processing
```
1. Build need map:
      for every char in t:
          need[char]++

2. Set required = need.size()
      (total distinct chars to satisfy)

3. Initialize:
      Track     = {}       (window frequency map)
      have      = 0        (chars satisfied)
      left      = 0        
      right     = 0        
      minWindow = INT_MAX  
      start     = 0        
```

---

### Main Loop
```
while right < size:

    ┌─────────────────────────────────────┐
    │           EXPAND                    │
    │                                     │
    │  Add s[right] into window:          │
    │      Track[s[right]]++              │
    │                                     │
    │  Check if char is satisfied:        │
    │      if Track[s[right]]             │
    │            == need[s[right]]:       │
    │          have++                     │
    └─────────────────────────────────────┘
                    │
                    ▼
    ┌─────────────────────────────────────┐
    │        CHECK VALIDITY               │
    │                                     │
    │      while have == required:        │
    │                                     │
    │  ┌───────────────────────────────┐  │
    │  │      RECORD MINIMUM           │  │
    │  │                               │  │
    │  │  if right-left+1 < minWindow: │  │
    │  │      minWindow = right-left+1 │  │
    │  │      start = left             │  │
    │  └───────────────────────────────┘  │
    │                                     │
    │  ┌───────────────────────────────┐  │
    │  │        SHRINK                 │  │
    │  │                               │  │
    │  │  Remove s[left] from window:  │  │
    │  │      Track[s[left]]--         │  │
    │  │                               │  │
    │  │  Check if char unsatisfied:   │  │
    │  │      if Track[s[left]]        │  │
    │  │            < need[s[left]]:   │  │
    │  │          have--               │  │
    │  │                               │  │
    │  │  Move left forward:           │  │
    │  │      left++                   │  │
    │  └───────────────────────────────┘  │
    │                                     │
    └─────────────────────────────────────┘
                    │
                    ▼
    ┌─────────────────────────────────────┐
    │           MOVE RIGHT                │
    │                                     │
    │           right++                   │
    └─────────────────────────────────────┘
```

---

### Post Processing
```
if minWindow == INT_MAX:
    return ""              ← no valid window exists

return s.substr(start, minWindow)
```

---

### State at each stage — `s="ADOBECODEBANC"` `t="ABC"`

```
Phase 1 — Expanding (have < required):
  right moves → 0,1,2,3,4,5
  window grows → "A","AD","ADO","ADOB","ADOBE","ADOBEC"
  have grows  → 1, 1,  1,   2,   2,    3  ← valid!

Phase 2 — Shrinking (have == required):
  record "ADOBEC" size=6
  remove A → have=2 → exit shrink
  
Phase 3 — Expanding again:
  right moves → 6,7,8,9,10
  window = "DOBECODEBA"
  have grows back to 3 ← valid!

Phase 4 — Shrinking:
  record size=10 (no update, 10>6)
  keep shrinking while valid...
  eventually left catches up

Phase 5 — Final valid window:
  window = "BANC" size=4
  record size=4 ✅ new minimum  start=9
  remove B → have=2 → exit

return s.substr(9, 4) = "BANC" ✅
```

---

### Key Rules Summary
```
1. have++ only when Track[c] == need[c]     (exactly meets requirement)
2. have-- only when Track[c] <  need[c]     (falls below requirement)
3. Record minimum BEFORE shrinking          (current window is valid)
4. Use while not if for shrinking           (find smallest valid window)
5. start captured at every new minimum      (track where window begins)
```

---

### Complexity
```
Time  → O(n)    right and left each traverse s once
Space → O(m)    need and Track hold at most |t| distinct chars
```

*/