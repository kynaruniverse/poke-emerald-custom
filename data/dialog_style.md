# Pokémon Daydream Version — Dialog Style Guide

## Core Rules

1. **Hard cap: 12 textboxes per cutscene.** Anything longer must be split across multiple scenes or cut entirely.
2. **Rule of purpose:** If an NPC line doesn't earn a smile or move the plot, cut it.
3. **Tutorials are environmental:** Signs, not lectures. The Professor explains nothing twice.
4. **Comedy is load-bearing:** Every joke should also deliver information.
5. **Dry > wacky:** Understatement lands harder than exclamation marks.

## Tone Reference

| Situation | Wrong (vanilla-style) | Right (Daydream-style) |
|---|---|---|
| Opening | "Welcome! The world of Pokémon is inhabited by creatures called..." | "You're late." |
| Starter pick | "These three Pokémon are waiting for a trainer just like you!" | "The good ones got picked yesterday. Box's by the door." |
| Route warning | "Wild Pokémon live in the tall grass! Be careful!" | Sign: "Tall grass. Pokémon live here. You know this." |
| Victory | "You're amazing! You beat me fair and square!" | "Okay. You're better at being awake than me. For now." |
| Quest start | "I have a very important mission for you, young trainer!" | "Five loaves. Dock. Before they go cold. You in?" |

## Textbox Budget

Each cutscene has a budget of **12 textboxes**. Count every `msgbox` call.

| Scene | Budget Used | Status |
|---|---|---|
| Prof. Mim intro | 3 | ✓ Done |
| Tibb first meeting | 4 | ✓ Done |
| Patty quest offer | 3 | ✓ Done |
| Innkeeper first meet | 3 | ✓ Done |
| Team Snooze reveal | TBD | Pending |
| Champion Vex intro | TBD | Pending |
| Horror arc midpoint | TBD | Pending |

## NPC Voice Notes

| Character | Voice | Example |
|---|---|---|
| Prof. Mim | Terse, academic, mildly exasperated | "You're late." |
| Tibb | Self-aware, sleepy, competitive | "Personal record." |
| Patty | Businesslike, warm underneath | "Bread waits for no one." |
| Innkeeper | Calm, practical, never surprised | "The beds will be here." |
| Director Hush | Reasonable-sounding, deeply tired | "Everyone deserves a break." |
| Champion Vex | Principled, on strike, not hostile | "I'm not coming back until conditions improve." |

## Prohibited Phrases

- "Young trainer"
- "The world of Pokémon"
- "I believe in you!"
- Any line longer than 3 lines in a single textbox
- Exclamation marks on factual statements
