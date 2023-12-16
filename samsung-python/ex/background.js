let removeTabs = false;

function removeTab(tab) {
  if (removeTabs) {
    chrome.tabs.query({}, function(tabs) {
      if (tabs.length > 4) {
        chrome.tabs.remove(tab.id);
      }
    });
  }
}

chrome.action.onClicked.addListener(function() {
  /* removeTabs = !removeTabs;
  if (removeTabs) {
    chrome.tabs.onCreated.addListener(removeTab);
  } else {
    chrome.tabs.onCreated.removeListener(removeTab);
  } */
});