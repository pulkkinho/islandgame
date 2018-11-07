# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [2.0.0]
### Changed
- Renamed Common::Vehicle to Common::Transport
- Wrapped Common::getGameRunner (and the whole initialization module) to namespace Initialization
- Common::Initialization::getGameRunner now handles players as std::vector<std::shared_ptr<Common::IPlayer>> instead of std::vector<Common::IPlayer*>


### Added
- Added new services to IGameEngine.
- Added implementations for Actor's and Transport's member functions.
- Added new services to Hex


### Removed
- Removed unnecessary services from Hex.


## [1.0.0] - 2018-10-25
### Added
- Initial release of GameLogic
